#ifndef SWAY_GRAPHICS_PREREQS_H
#define SWAY_GRAPHICS_PREREQS_H

#include <sway/core.h>
#include <sway/math.h>
#include <sway/gapi/gl.h>

#include <iostream> // std::cout
#include <vector> // std::vector
#include <functional> // std::bind
#include <algorithm> // std::sort
#include <memory> // std::shared_ptr, std::make_shared

#include <boost/unordered_map.hpp> // boost::unordered_map
#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/property_tree/ptree.hpp> // boost::property_tree::ptree

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(graphics)

template <typename TYPE> class TVertexChannel;
class VertexData;
class StaticMesh;
class Material;
class MaterialManager;
class Drawable;
class RenderSubqueue;
class RenderQueue;
class RenderSubsystem;

typedef std::shared_ptr<class TVertexChannel<math::vec3f_t>> VertexChannelRef_t;
typedef boost::unordered_map<gapi::VertexSemantic_t, VertexChannelRef_t> VertexChannelRefUmap_t;

typedef std::shared_ptr<class VertexData> VertexDataRef_t;
typedef std::shared_ptr<class StaticMesh> StaticMeshRef_t;
typedef std::shared_ptr<class Material> MaterialRef_t;
typedef std::shared_ptr<class MaterialManager> MaterialManagerRef_t;

typedef std::shared_ptr<class Drawable> DrawableRef_t;
typedef std::vector<DrawableRef_t> DrawableRefVec_t;

typedef std::shared_ptr<class RenderSubqueue> RenderSubqueueRef_t;
typedef std::vector<RenderSubqueueRef_t> RenderSubqueueRefVec_t;

typedef std::shared_ptr<class RenderQueue> RenderQueueRef_t;
typedef std::vector<RenderQueueRef_t> RenderQueueRefVector_t;

typedef std::shared_ptr<class RenderSubsystem> RenderSubsystemRef_t;

NAMESPACE_END(graphics)
NAMESPACE_END(sway)

#endif // SWAY_GRAPHICS_PREREQS_H
