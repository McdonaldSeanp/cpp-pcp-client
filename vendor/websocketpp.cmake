INCLUDE(ExternalProject)

# Add an external project to build websocketpp
EXTERNALPROJECT_ADD(
    websocketpp
    PREFIX "${PROJECT_BINARY_DIR}"
    URL "file://${VENDOR_DIRECTORY}/websocketpp-0.7.0.patch.zip"
    URL_MD5 "920f28fa91f551885825c1f3971bafac"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)

EXTERNALPROJECT_GET_PROPERTY(websocketpp SOURCE_DIR)
SET(WEBSOCKETPP_INCLUDE_DIRS "${SOURCE_DIR}")
