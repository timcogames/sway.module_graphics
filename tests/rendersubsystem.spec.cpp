#include <boost/test/unit_test.hpp>
#include <memory> // std::shared_ptr, std::make_shared

#include <sway/core.h>
#include <sway/core/intrusive/priorities.h>
#include <sway/graphics.h>

using namespace sway;

class RenderSubsystemFixture : public core::foundation::Context {
public:
	RenderSubsystemFixture() {
		_subsystem = std::make_shared<graphics::RenderSubsystem>(this);
		BOOST_CHECK_NO_THROW(registerObject(_subsystem.get()));
	}

	virtual ~RenderSubsystemFixture() {
		// Empty
	}

private:
	std::shared_ptr<graphics::RenderSubsystem> _subsystem;
};

BOOST_FIXTURE_TEST_SUITE(RenderSubsystem_FixtureTestSuite, RenderSubsystemFixture);

BOOST_AUTO_TEST_CASE(RenderSubsystemFixture_TestCase) {
	auto queue_h = static_cast<graphics::RenderSubsystem *>(getObject("RenderSubsystem"))->createQueue();
	queue_h->setPriority(core::intrusive::kPriority_High);
	queue_h->addSubqueue(std::make_shared<graphics::RenderSubqueue>());
	auto subqueueGroup_h = queue_h->getSubqueues(graphics::RenderSubqueueGroup_t::kTransparent);

	auto queue_l = static_cast<graphics::RenderSubsystem *>(getObject("RenderSubsystem"))->createQueue();
	queue_l->setPriority(core::intrusive::kPriority_Low);
	queue_l->addSubqueue(std::make_shared<graphics::RenderSubqueue>());
	auto subqueueGroup_l = queue_l->getSubqueues(graphics::RenderSubqueueGroup_t::kTransparent);
 
	auto queue_n = static_cast<graphics::RenderSubsystem *>(getObject("RenderSubsystem"))->createQueue();
	queue_n->setPriority(core::intrusive::kPriority_Normal);
	queue_n->addSubqueue(std::make_shared<graphics::RenderSubqueue>());
	auto subqueueGroup_n = queue_n->getSubqueues(graphics::RenderSubqueueGroup_t::kTransparent);

	auto unsortedQueues = static_cast<graphics::RenderSubsystem *>(getObject("RenderSubsystem"))->getQueues();
	BOOST_CHECK_EQUAL(unsortedQueues.size(), size_t(3));

	static_cast<graphics::RenderSubsystem *>(getObject("RenderSubsystem"))->sortQueues();

	auto sortedQueues = static_cast<graphics::RenderSubsystem *>(getObject("RenderSubsystem"))->getQueues();
	BOOST_CHECK(std::is_sorted(sortedQueues.begin(), sortedQueues.end(), graphics::RenderQueue::PriorityInDescendingOrder()) == true);
}

BOOST_AUTO_TEST_SUITE_END();
