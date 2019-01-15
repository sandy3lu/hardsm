package com.yunjingit.common;


import java.io.IOException;
import java.lang.reflect.Field;

public class SMTool {
    public static void main( String[] args ) throws IOException, SMException {
        ///home/sandy/Downloads/src/hardsm


        //addLibraryDir(dir);
        CSMApiImpl csmApi = new CSMApiImpl();
        csmApi.api_init();
        csmApi.api_final();
    }



    private static void addLibraryDir(String libraryPath)  {
        Field userPathsField = null;
        try {
            userPathsField = ClassLoader.class.getDeclaredField("usr_paths");
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }
        userPathsField.setAccessible(true);
        String[] paths = new String[0];
        try {
            paths = (String[]) userPathsField.get(null);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < paths.length; i++) {
            if (libraryPath.equals(paths[i])) {
                continue;
            }
            sb.append(paths[i]).append(';');
        }
        sb.append(libraryPath);
        System.setProperty("java.library.path", sb.toString());
        final Field sysPathsField;
        try {
            sysPathsField = ClassLoader.class.getDeclaredField("sys_paths");
            sysPathsField.setAccessible(true);
            sysPathsField.set(null, null);
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

    }
}


