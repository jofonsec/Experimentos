######################################################################################
### Copia los archivos "param" a la carpeta de compilación para un facil uso
### 	UNIX
### --> ejecutar "make instalar" para copiar los archivos en el directorio donde se
###	construye la aplicación
###
###	Windows
### --> ejecutar "mingw32-make instalar" para copiar los archivos en el directorio donde se
###	construye la aplicación
######################################################################################

add_custom_target(instalar DEPENDS 
			${CMAKE_SOURCE_DIR}/datos/ags-ax-svn.param
			${CMAKE_SOURCE_DIR}/datos/ags-ax-swap.param
			${CMAKE_SOURCE_DIR}/datos/ags-ax-um.param
			${CMAKE_SOURCE_DIR}/datos/ags-sbx-svn.param
			${CMAKE_SOURCE_DIR}/datos/ags-sbx-swap.param
			${CMAKE_SOURCE_DIR}/datos/ags-sbx-um.param
			${CMAKE_SOURCE_DIR}/datos/ags-ux-svn.param
			${CMAKE_SOURCE_DIR}/datos/ags-ux-swap.param
			${CMAKE_SOURCE_DIR}/datos/Anclas.txt
			${CMAKE_SOURCE_DIR}/datos/Allposition.txt
			${CMAKE_SOURCE_DIR}/datos/Matriz1.txt
			${CMAKE_SOURCE_DIR}/datos/Matriz2.txt
			${CMAKE_SOURCE_DIR}/datos/Matriz3.txt
			${CMAKE_SOURCE_DIR}/datos/Matriz4.txt
			${CMAKE_SOURCE_DIR}/datos/Semilla.sav
				  ${CMAKE_SOURCE_DIR}/datos)

add_custom_command(
    TARGET instalar
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
 
    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-ax-svn.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-ax-swap.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-ax-um.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-sbx-svn.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-sbx-swap.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-sbx-um.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-ux-svn.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-ux-swap.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/ags-ux-um.param
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Anclas.txt
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Allposition.txt
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Matriz1.txt
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Matriz2.txt
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Matriz3.txt
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Matriz4.txt
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}

    ARGS -E copy_if_different
      ${CMAKE_SOURCE_DIR}/datos/Semilla.sav
      ${CMAKE_BINARY_DIR}/application
    COMMAND ${CMAKE_COMMAND}
)

