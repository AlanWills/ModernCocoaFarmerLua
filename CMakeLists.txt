set(LIBS 
    CelesteLua
    ModernCocoaFarmerLibrary)

build_library(NAME ModernCocoaFarmerLua FOLDER "Modern Cocoa Farmer/Lua" TYPE STATIC LIBS "${LIBS}")