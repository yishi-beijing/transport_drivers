
#ifndef TCP_DRIVER__VISIBILITY_CONTROL_HPP_
#define TCP_DRIVER__VISIBILITY_CONTROL_HPP_

#if defined(__WIN32)
#if defined(TCP_DRIVER_BUILDING_DLL) || defined(TCP_DRIVER_EXPORTS)
#define TCP_DRIVER_PUBLIC __declspec(dllexport)
#define TCP_DRIVER_LOCAL
#else  // defined(TCP_DRIVER_BUILDING_DLL) || defined(TCP_DRIVER_EXPORTS)
#define TCP_DRIVER_PUBLIC __declspec(dllimport)
#define TCP_DRIVER_LOCAL
#endif  // defined(TCP_DRIVER_BUILDING_DLL) || defined(TCP_DRIVER_EXPORTS)
#elif defined(__linux__)
#define TCP_DRIVER_PUBLIC __attribute__((visibility("default")))
#define TCP_DRIVER_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
#define TCP_DRIVER_PUBLIC __attribute__((visibility("default")))
#define TCP_DRIVER_LOCAL __attribute__((visibility("hidden")))
#else  // defined(_LINUX)
#error "Unsupported Build Configuration"
#endif  // defined(_WINDOWS)

#endif  // TCP_DRIVER__VISIBILITY_CONTROL_HPP_
