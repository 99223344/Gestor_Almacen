# Sistema de Gestión de Inventario en C++ 


## Aplicación de Consola

Aplicación de consola desarrollada en C++ para administrar un inventario de productos utilizando std::list como estructura de datos dinámica. El sistema permite registrar, consultar, modificar y eliminar productos, además de generar reportes en archivos de texto y calcular el valor total del inventario. Incluye validación robusta de entrada, normalización de texto, menús interactivos y un diseño modular que facilita la lectura y mantenimiento del código.


## Características principales
* Agregar productos con nombre, marca, categoría, precio y unidades.
* Mostrar inventario completo en formato legible.
* Buscar productos por nombre, con normalización a mayúsculas.
* Modificar productos existentes, actualizando cualquier campo.
* Eliminar productos de manera segura mediante iteradores.
* Buscar por categoría, mostrando solo los productos correspondientes.
* Calcular el valor total del inventario, multiplicando precio × unidades.
* Generar reportes en archivo .txt, con formato profesional y conteo total.
* Validación de entrada numérica y textual, evitando errores del usuario.
* Menú interactivo con control de flujo y pausas seguras.
* Función Pausa mejorada, sin necesidad de presionar doble ENTER.



###  Tecnologías y conceptos aplicados
* C++17
* std::list para manejo dinámico de datos
* std::transform para normalizar texto
* Manejo de archivos con fstream
* Validación de entrada (cin, cin.clear(), cin.ignore())
* Programación modular
* Diseño de menús y control de flujo
* Separación lógica entre funciones principales y auxiliares

## Estructura del Proyecto

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Estructura.png) 

## Objetivo del proyecto
Este proyecto forma parte de un portafolio orientado a demostrar habilidades prácticas en C++ mediante la construcción de aplicaciones reales. El sistema muestra dominio de estructuras de datos dinámicas, validación de entrada, manejo de archivos, diseño modular y buenas prácticas de programación en consola.

🚀 Mejoras futuras
- Guardar y cargar inventario desde archivo al iniciar/cerrar el programa.
- Ordenar productos por nombre, precio o categoría.
- Exportar reporte en formato CSV.
- Implementar un sistema de IDs únicos para cada producto.
- Añadir colores a la consola para mejorar la interfaz.
- Agregar filtros avanzados (por precio, rango de unidades, marca, etc.).

## Capturas del Programa
* Menu -------------------------

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Menu.png)

* Busqueda de inventario ------

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Busqueda_Inventario.png) 

* Busqueda por categoria ------

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Busqueda_por_Categoria.png) 

* Eliminacion de Productos----

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Eliminacion_Producto.png) 

* Lista de Invetario --------

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Lista_Inventario.png) 

* Modificar Productos-------

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Modificar_Producto.png) 

* Registro de Productos ----

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Registro_Producto.png) 

* Suma total----------------

![This is an alt](https://github.com/99223344/Gestor_Almacen/blob/7162c2352ed60d923358479f57d39bb96af6e677/Almacen/Suma_Total.png) 


