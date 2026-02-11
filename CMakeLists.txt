cmake_minimum_required (VERSION 3.10)
project ("compatibilita_project")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- CORREZIONE WARNING C26819 ---
# Questo comando dice al compilatore di ignorare il warning del 'fallthrough' 
# e impedisce che gli avvisi blocchino l'avvio del programma (/WX-)
if(MSVC)
    add_compile_options(/wd26819 /WX-)
endif()

# Cerca Drogon (modalità CONFIG per vcpkg)
find_package(Drogon CONFIG REQUIRED)

# Configurazione dell'eseguibile
add_executable (compatibilita_exe 
    "compatibilita_project/compatibilita_project.cpp" 
    "compatibilita_project/compatibilita_project.h"
    "compatibilita_project/models/CompatibilitaEngine.h"
    "compatibilita_project/controllers/CalcolatoreController.h"
)

# Collegamento della libreria
target_link_libraries(compatibilita_exe PRIVATE Drogon::Drogon)

# Imposta la directory di lavoro per il debugger
set_target_properties(compatibilita_exe PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")