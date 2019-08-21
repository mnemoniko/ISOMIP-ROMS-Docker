## This is a Dockerfile. It establishes the container and loads packages.
## This example runs the ISOMIP+ domain on 4 processors for 1 year of simulation

# Set base OS, from a stable, maintained Docker image
#FROM debian:stable
FROM buildpack-deps:stretch

# Software packages to run ROMS
RUN apt-get update && apt-get -yq install \
    binutils \
    build-essential \
    cmake \
    emacs \
    flex \
    gfortran \
    libnetcdf-dev \
    libopenmpi-dev \
    openmpi-bin \
    git \
    sudo

RUN apt-get update --fix-missing
RUN apt-get install -yq libnetcdff6 libnetcdff-dev

# Set work directory
WORKDIR /home/user

# Grab the relevant branch of ROMS v3.6
RUN git clone --branch Docker_example https://github.com/mnemoniko/ROMS36.git

# Copy application specific files into container
COPY makefile /home/user/ROMS36/
RUN mkdir /home/user/Input
COPY isomip_plus.h /home/user/Input/
COPY isomip_grd.v8.1km.nc /home/user/Input/
COPY ocean_isomip_plus.in /home/user/Input/

# Set environment variables
ENV ROMS_APPLICATION=ISOMIP_PLUS
ENV MY_ROMS_DIR=/home/user/ROMS36
ENV COMPILER=${MY_ROMS_DIR}/Compilers \
    USE_MPI=on \
    USE_MPIF90=on \
    which_MPI=openmpi \
    FORT=gfortran \
    USE_LARGE=on \
    USE_NETCDF4=on \
    MY_HEADER_DIR=/home/user/Input \
    MY_ANALYTICAL_DIR=${MY_ROMS_DIR}/ROMS/Functionals \
    SCRATCH_DIR=${MY_ROMS_DIR}/Build \
    NETCDF_INCDIR=/usr/include \
    NETCDF_LIBDIR=/usr/lib/x86_64-linux-gnu \
    NC_CONFIG=/usr/bin/nf-config

# Compile ROMS
#RUN cd ROMS36 && make

# Prepare for recording output
RUN mkdir /home/user/Output

## Useful commands:
## Build container: docker build --tag roms-isomip .
## Run interactively: docker run --interactive --tty roms-isomip:latest bash
