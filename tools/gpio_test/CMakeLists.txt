option ( GPIO_TEST "Compile gpio_test ?" ON )

if ( GPIO_TEST )


	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
	LINK_DIRECTORIES(${${PROJECT_NAME}_BINARY_DIR})

	### File Lists

	file( GLOB gpio_test_src "src/*.c" )
	file( GLOB gpio_test_hdr "src/*.h")

	### Targets

	add_executable( "gpio_test" ${gpio_test_src} ${gpio_test_hdr} )

	TARGET_LINK_LIBRARIES( "gpio_test" ${PROJECT_NAME} )

	### INSTAll

	install( TARGETS "gpio_test" 
			LIBRARY DESTINATION "${INSTALL_LIB_PATH}/vs_plugins"  COMPONENT main 
			RUNTIME DESTINATION "${INSTALL_BIN_PATH}/vs_plugins"  COMPONENT main )

else ( GPIO_TEST )

	message ( WARNING "gpio_test will not be included" )

endif ( GPIO_TEST )
