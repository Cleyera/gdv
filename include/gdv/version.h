/**
* \file version.h
* \brief define version of gdv.
**/
#ifdef GDV_VERSION_H_
#define GDV_VERSION_H_

/**
* \def GDV_VERSION
* \brief gdv version.
**/
#define GDV_VERSION (0x00000000UL)

/**
* \def GDV_VERSION_STRING
* \brief gdv version.
**/
#define GDV_VERSION_STRING "0.0.0a"

namespace gdv {

namespace version {

/**
* \brief gdv version.
**/
static constexpr unsigned long gdv_version = GDV_VERSION;

/**
* \brief gdv version.
**/
static constexpr const char* gdv_version_string = GDV_VERSION_STRING;

} // namespace version
} // namespace gdv

#endif
