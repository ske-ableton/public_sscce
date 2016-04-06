
When this example is built with clang on linux, the two
plugins disagree on the typeid of a shared type, causing
the registry shared between them to construct a new object
for an already registered type.

    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .
    $ ./main 
	8SomeType
	in plugin1 0x12aeb70
	in plugin1 0x12aeb70
	8SomeType
	in plugin2 0x12afa80
	in plugin2 0x12afa80

This does not happen if -stdlib=libc++ is omitted (then libstdc++
is used instead).

Loading the plugin with the QLibrary::ExportExternalSymbolsHint
loadHint also avoids the problem.

This happens whether or not Qt is built with libc++

	ldd  /home/stephen/dev/prefix-clang/lib/libQt5Core.so.5.6.1 main lib* | grep -P "libc\+\+|:"
	/home/stephen/dev/prefix-clang/lib/libQt5Core.so.5.6.1:
	        libc++.so.1 => /usr/lib/x86_64-linux-gnu/libc++.so.1 (0x00007f9f95d3c000)
	main:
	        libc++.so.1 => /usr/lib/x86_64-linux-gnu/libc++.so.1 (0x00007fc6f084a000)
	libmydependency.so:
	        libc++.so.1 => /usr/lib/x86_64-linux-gnu/libc++.so.1 (0x00007fcd67e56000)
	libmyplugin.so:
	        libc++.so.1 => /usr/lib/x86_64-linux-gnu/libc++.so.1 (0x00007f9e19aea000)
	libotherplugin.so:
	        libc++.so.1 => /usr/lib/x86_64-linux-gnu/libc++.so.1 (0x00007fe5aa928000)
