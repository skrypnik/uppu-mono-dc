function( deploy_targets TARGETS_TO_DEPLOY )

    set( CPACK_PACKAGE_NAME "uppu-mono-dc" )

    set( CPACK_VERBATIM_VARIABLES YES )

    set( CPACK_PACKAGE_VENDOR "www.mars-energo.ru" )
    set( CPACK_DEBIAN_PACKAGE_MAINTAINER "www.mars-energo.ru" )
    set( CPACK_PACKAGE_DESCRIPTION_SUMMARY ${TARGETS_TO_DEPLOY} )

    set( CPACK_PACKAGING_INSTALL_PREFIX "/opt/mars-energo" )

    set( CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR} )
    set( CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR} )
    set( CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH} )

    set( CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME} )
    set( CPACK_OUTPUT_FILE_PREFIX ${CMAKE_SOURCE_DIR}/../.deploy )

    set( CPACK_COMPONENTS_GROUPING ONE_PER_GROUP )
    set( CPACK_DEBIAN_FILE_NAME DEB-DEFAULT )
    set( CPACK_DEB_COMPONENT_INSTALL YES )

    ##############################################
    # \todo
    ##############################################

    include( CPack )

endfunction()
