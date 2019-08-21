/*
** svn $Id: icetest.h 1307 2008-01-10 00:22:36Z bgalton $
*******************************************************************************
** Copyright (c) 2002-2008 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Ice Shelf Ocean Model Intercomparison (ISOMIP) Experiment.
**
** Application flag:   ISOMIP_PLUS
** Input script:       ocean_isomip_plus.in
*/

#define UV_ADV
#define DJ_GRADPS
#define UV_COR
#define UV_VIS2
#define UV_QDRAG
#define MIX_GEO_UV
#undef MIX_S_UV
#undef TS_C4HADVECTION
#define TS_U3HADVECTION
#define TS_C4VADVECTION
#define TS_DIF2
#define MIX_GEO_TS
#undef  MIX_S_TS
#define SOLVE3D
#define SALINITY
#define NONLIN_EOS
#define CURVGRID
/* #define SPHERICAL */ 
#define MASKING

#define SPLINES_VDIFF
#define SPLINES_VVISC
#define SPLINES
#define AVERAGES
#undef ATM_PRESS
#undef ANA_PAIR
#define PERFECT_RESTART
#undef ANA_GRID
#define ANA_INITIAL
#define ANA_SMFLUX
#define ANA_STFLUX
#define ANA_SSFLUX
#define ANA_BSFLUX
#define ANA_BTFLUX
#define ANA_SRFLUX

#define TCLIMATOLOGY
#define ANA_TCLIMA
#define TCLM_NUDGING
#undef ANA_NUDGCOEF

#undef ANA_SEAICE
#undef ICE_MODEL
#ifdef ICE_MODEL
# undef ICE_SHOREFAST
# define ICE_THERMO
# define ICE_MK
# define ICE_ALB_EC92
# define ICE_CONVSNOW
# define ICE_MOMENTUM
# define ICE_MOM_BULK
# define ICE_EVP
# define ICE_ADVECT
# define ICE_SMOLAR
# define ICE_UPWIND
# undef ICE_SMOOTH
# define ANA_HIOBC
# define ANA_HSNOBC
#endif

#undef BULK_FLUXES
#ifdef BULK_FLUXES
# ifdef ICE_MODEL
#  define ICE_BULK_FLUXES
# endif
# define LONGWAVE
# define EMINUSP
# define SOLAR_SOURCE
# define CLOUDS
#endif

#define ICESHELF
#define ICESHELF_3EQ

#ifdef ISOMIP_PLUS
# define ISOMIP_PLUS_INIWARM
# define ISOMIP_PLUS_FORCEWARM
# undef ISOMIP_PLUS_INICOLD
# undef ISOMIP_PLUS_FORCECOLD
#endif

#undef  ANA_VMIX
#undef MY25_MIXING
#define RI_SPLINES
#define LMD_MIXING

#ifdef  LMD_MIXING
# define LMD_CONVEC 
# define LMD_RIMIX
# define LMD_SKPP
# define LMD_NONLOCAL
# define LMD_BKPP
# undef LMD_SHAPIRO
#endif
