# Assessing-Actinium-225-Efficacy-in-Alpha-Therapy
GEANT4 based simulation of the the interactions of Actinium-225 (225Ac) in targeted alpha therapy (TAT).


The primary goal is to evaluate the effectiveness of 225Ac in delivering high-energy alpha radiation to cancer cells, while minimizing exposure to surrounding healthy tissues.

Key Features:

    Simulation of 225Ac Decay and Alpha Emission: The GEANT4 simulation accurately models the decay chain of Actinium-225, which emits multiple alpha particles during its decay. These alpha particles are modeled to interact with cancerous tissues, focusing on energy deposition and radiation damage.

    Detailed Particle Interactions: GEANT4’s powerful physics engine simulates the interactions of alpha particles with biological materials. The simulation tracks the energy deposition at a microscopic level, accounting for processes such as ionization, excitation, and scattering.

    Geometries and Materials:
        Tumor and Surrounding Tissue: The simulated geometry includes a tumor region modeled as a spherical volume, surrounded by healthy tissue. Each region is assigned specific material properties, such as density and elemental composition, to accurately reflect biological tissues.
        Actinium-225 Source: The Actinium-225 source is embedded within or near the tumor volume. The source geometry is defined to mimic realistic distribution patterns of radioisotopes in targeted therapies.
        World Volume: A larger world volume encloses the entire setup, ensuring that all relevant interactions are captured within the simulation.

    Physics Processes:
        Electromagnetic Processes: GEANT4’s electromagnetic physics processes are used to simulate the interactions of alpha particles with matter, including ionization, Bremsstrahlung, and multiple scattering.
        Radioactive Decay: The radioactive decay process models the emission of alpha particles from 225Ac and its daughter isotopes, simulating the entire decay chain.
        Energy Deposition and Dose Calculation: The simulation calculates the energy deposited in both the tumor and surrounding healthy tissues, which is critical for evaluating the therapeutic effectiveness and potential side effects.

    Optimization of Treatment Parameters: By adjusting the geometry, source distribution, and simulation parameters, the project seeks to optimize the radiation dose delivered specifically to cancer cells, improving the efficacy of the treatment while reducing unwanted damage to healthy tissues.

    Data Analysis and Visualization: The energy deposition data, along with other metrics such as particle fluence and track lengths, are recorded and outputted to a ROOT file. This allows for detailed post-processing, analysis, and visualization, enabling researchers to assess the effectiveness of the simulated therapy.

CMake Configuration (CMakeLists.txt):

    Configures the build system to locate and use the GEANT4 libraries.
    Sets up directories, compiler flags, and creates the executable ActiniumSimulation.

Main Program (main.cc):

    Initializes the run manager and defines the simulation’s scope.
    Sets up the detector construction, physics list, and primary generator actions.
    Configures the visualization manager and user interface, executing vis.mac for graphical representation of the simulation.

Visualization Macro (vis.mac):

    Defines the visualization environment, including camera viewpoints, zoom level, and the visualization of particle tracks.
    Configures the display of geometries and material boundaries, aiding in visual inspection of the simulation setup.

Detector Construction (DetectorConstruction.cc/hh):

    Constructs the world volume and defines the geometry of the tumor and surrounding tissues.
    Assigns material properties to each volume, such as density and elemental composition, which are critical for accurate simulation of radiation interactions.
    Incorporates visualization attributes to distinguish between different materials and geometries during simulation.

Physics List (PhysicsList.cc/hh):

    Registers the relevant physics processes, including electromagnetic interactions, radioactive decay, and energy deposition.
    Ensures the simulation accurately models the behavior of alpha particles as they traverse through biological tissues.

Primary Generator Action (PrimaryGeneratorAction.cc/hh):

    Defines a particle gun that simulates the emission of alpha particles from the 225Ac source, specifying parameters such as energy, direction, and spatial distribution.

Run Action (RunAction.cc/hh) & Event Action (EventAction.cc/hh):

    Implement functions to manage actions at the beginning and end of each run and event, including the collection and storage of simulation data.
    Track cumulative energy deposition and other relevant metrics across multiple simulation runs.

Stepping Action (SteppingAction.cc/hh):

    Handles actions at each simulation step, such as tracking particle movement and interactions.
    Records energy deposition at each step within the tumor and surrounding tissues, contributing to dose calculation.

Sensitive Detector (SensitiveDetector.cc/hh):

    Processes hits within the defined sensitive volumes (e.g., tumor and healthy tissues), recording energy deposition, interaction points, and secondary particle generation.
    Outputs detailed data on the interactions, which can be analyzed to assess the radiation dose delivered to different regions.

This comprehensive simulation provides valuable insights into the potential of 225Ac in targeted alpha therapy, aiding in the refinement of cancer treatment protocols.

