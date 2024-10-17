// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gazebo_map_creator_interface:srv/MapRequest.idl
// generated code does not contain a copyright notice

#ifndef GAZEBO_MAP_CREATOR_INTERFACE__SRV__DETAIL__MAP_REQUEST__TRAITS_HPP_
#define GAZEBO_MAP_CREATOR_INTERFACE__SRV__DETAIL__MAP_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gazebo_map_creator_interface/srv/detail/map_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'lowerright'
// Member 'upperleft'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace gazebo_map_creator_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const MapRequest_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: lowerright
  {
    out << "lowerright: ";
    to_flow_style_yaml(msg.lowerright, out);
    out << ", ";
  }

  // member: upperleft
  {
    out << "upperleft: ";
    to_flow_style_yaml(msg.upperleft, out);
    out << ", ";
  }

  // member: skip_vertical_scan
  {
    out << "skip_vertical_scan: ";
    rosidl_generator_traits::value_to_yaml(msg.skip_vertical_scan, out);
    out << ", ";
  }

  // member: resolution
  {
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << ", ";
  }

  // member: range_multiplier
  {
    out << "range_multiplier: ";
    rosidl_generator_traits::value_to_yaml(msg.range_multiplier, out);
    out << ", ";
  }

  // member: threshold_2d
  {
    out << "threshold_2d: ";
    rosidl_generator_traits::value_to_yaml(msg.threshold_2d, out);
    out << ", ";
  }

  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MapRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lowerright
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lowerright:\n";
    to_block_style_yaml(msg.lowerright, out, indentation + 2);
  }

  // member: upperleft
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "upperleft:\n";
    to_block_style_yaml(msg.upperleft, out, indentation + 2);
  }

  // member: skip_vertical_scan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "skip_vertical_scan: ";
    rosidl_generator_traits::value_to_yaml(msg.skip_vertical_scan, out);
    out << "\n";
  }

  // member: resolution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << "\n";
  }

  // member: range_multiplier
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_multiplier: ";
    rosidl_generator_traits::value_to_yaml(msg.range_multiplier, out);
    out << "\n";
  }

  // member: threshold_2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "threshold_2d: ";
    rosidl_generator_traits::value_to_yaml(msg.threshold_2d, out);
    out << "\n";
  }

  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MapRequest_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gazebo_map_creator_interface

namespace rosidl_generator_traits
{

[[deprecated("use gazebo_map_creator_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gazebo_map_creator_interface::srv::MapRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gazebo_map_creator_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gazebo_map_creator_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const gazebo_map_creator_interface::srv::MapRequest_Request & msg)
{
  return gazebo_map_creator_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gazebo_map_creator_interface::srv::MapRequest_Request>()
{
  return "gazebo_map_creator_interface::srv::MapRequest_Request";
}

template<>
inline const char * name<gazebo_map_creator_interface::srv::MapRequest_Request>()
{
  return "gazebo_map_creator_interface/srv/MapRequest_Request";
}

template<>
struct has_fixed_size<gazebo_map_creator_interface::srv::MapRequest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gazebo_map_creator_interface::srv::MapRequest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gazebo_map_creator_interface::srv::MapRequest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gazebo_map_creator_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const MapRequest_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MapRequest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MapRequest_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gazebo_map_creator_interface

namespace rosidl_generator_traits
{

[[deprecated("use gazebo_map_creator_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gazebo_map_creator_interface::srv::MapRequest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gazebo_map_creator_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gazebo_map_creator_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const gazebo_map_creator_interface::srv::MapRequest_Response & msg)
{
  return gazebo_map_creator_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gazebo_map_creator_interface::srv::MapRequest_Response>()
{
  return "gazebo_map_creator_interface::srv::MapRequest_Response";
}

template<>
inline const char * name<gazebo_map_creator_interface::srv::MapRequest_Response>()
{
  return "gazebo_map_creator_interface/srv/MapRequest_Response";
}

template<>
struct has_fixed_size<gazebo_map_creator_interface::srv::MapRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gazebo_map_creator_interface::srv::MapRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gazebo_map_creator_interface::srv::MapRequest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gazebo_map_creator_interface::srv::MapRequest>()
{
  return "gazebo_map_creator_interface::srv::MapRequest";
}

template<>
inline const char * name<gazebo_map_creator_interface::srv::MapRequest>()
{
  return "gazebo_map_creator_interface/srv/MapRequest";
}

template<>
struct has_fixed_size<gazebo_map_creator_interface::srv::MapRequest>
  : std::integral_constant<
    bool,
    has_fixed_size<gazebo_map_creator_interface::srv::MapRequest_Request>::value &&
    has_fixed_size<gazebo_map_creator_interface::srv::MapRequest_Response>::value
  >
{
};

template<>
struct has_bounded_size<gazebo_map_creator_interface::srv::MapRequest>
  : std::integral_constant<
    bool,
    has_bounded_size<gazebo_map_creator_interface::srv::MapRequest_Request>::value &&
    has_bounded_size<gazebo_map_creator_interface::srv::MapRequest_Response>::value
  >
{
};

template<>
struct is_service<gazebo_map_creator_interface::srv::MapRequest>
  : std::true_type
{
};

template<>
struct is_service_request<gazebo_map_creator_interface::srv::MapRequest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gazebo_map_creator_interface::srv::MapRequest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GAZEBO_MAP_CREATOR_INTERFACE__SRV__DETAIL__MAP_REQUEST__TRAITS_HPP_
