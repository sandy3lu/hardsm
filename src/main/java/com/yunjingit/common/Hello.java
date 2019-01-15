package com.yunjingit.common;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;




    /** Simple example of JNA interface mapping and usage. */
    public class Hello {

        // This is the standard, stable way of mapping, which supports extensive
        // customization and mapping of Java to native types.
        public interface CLibrary extends Library {
            CLibrary INSTANCE = (CLibrary)
                    Native.load((Platform.isWindows() ? "msvcrt" : "smwstb"),
                            CLibrary.class);

            void SM_OpenDevice(String format, Object... args);
        }


        public static void main(String[] args) {

            String dir = System.getProperty("user.dir") ;
            System.setProperty("jna.library.path", dir);
            CSMApi obj = CSMApi.INSTANCE  ;
            byte[] buf = new byte[256];
            obj.api_init(buf);


        }
    }



