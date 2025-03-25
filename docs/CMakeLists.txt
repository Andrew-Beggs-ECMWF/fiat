if( HAVE_DOCS_MARKDOWN )
  list( APPEND fiat_doc_builders markdown )
endif()

if( HAVE_DOCS_LATEXPDF )
  list( APPEND fiat_doc_builders latexpdf )
endif()

if( HAVE_DOCS_HTML )
  list( APPEND fiat_doc_builders html )
endif()

foreach( builder IN LISTS fiat_doc_builders )
  foreach( filepath fiat/drhook )
  #TODO: Get last bit of project path to gen target name
    add_custom_target( doc_drhook_${builder}
        COMMAND sphinx-build -M ${builder} . _build
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${filepath}
        )
        add_dependencies( fiat doc_drhook_${builder} )
  endforeach()
endforeach()
