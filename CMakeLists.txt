set(LIBS 
    CelesteLua
    ModernCocoaFarmerLibrary)

build_library(NAME ModernCocoaFarmerLua FOLDER "Modern Cocoa Farmer" TYPE STATIC LIBS "${LIBS}")