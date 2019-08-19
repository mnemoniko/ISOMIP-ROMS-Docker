# ISOMIP-ROMS-Docker
Running the ISOMIP+ simulation using ROMS v3.6 and Docker

### Summary
TBD

### ISOMIP+
The Ice Shelf Ocean Modeling Intercomparison Project (ISOMIP+) is a MIP designed to compare simulations of ocean models that include a static ice shelf.  The domain is idealized, and a series of forcings and initial conditions are described in [Asay-Davis et al, 2016](https://www.geosci-model-dev.net/9/2471/2016/gmd-9-2471-2016.html). Here it is used as the example simulation, to demonstrate how containerization works.


### ROMS v3.6
The Regional Ocean Modelling System (ROMS) is a primitive equation ocean model with terrain-following vertical coordinates. A significant number of research groups use ROMS for regions that include ice shelves (list of examples plus links). ROMS is also widely used for a variety of other regional applications, and the example containerization code here is generalizable to the main ROMS trunk.


### Docker
Docker is a containerization software: following a Dockerfile script, it builds a lightweight container that functions as a virtual OS. Unlike a standard virtual machine, the container only includes packages specific to running a single application, and often starts, runs, and shuts down after performing a single task. Once built, the container can be uploaded, archived, and shared on DockerHub.


### Singularity
Like Docker, Singularity is a containerization software. It is built specifically to run Dockerfiles on large clusters, where the user may not have administrator-type privileges. We have not yet tested it with the Dockerfiles included here.
