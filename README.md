# netbsd8-clang
NetBSD-8  built with clang only and USING MODULAR X11
Why Modular X11???  just because xf86-video-intel aborts core when compiled with clang
because clang DOES NOT initialize structures with ZEROS..
This is NetBSD8 built with llvm/clang with all the fixes in pkgsrc and /etc/mk.conf to amke it happen
