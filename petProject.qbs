import qbs

CppApplication {

    property string Home: path
    property string BSP: path + "/BSP"
    property string Drawing: BSP + "/Drawing"
    property string Moving: BSP + "/Moving"
    consoleApplication: true
    install: true
    files:[
        Home + "/main.c",
        Home + "/main.h",
        Drawing + "/**",
        Moving + "/**",
    ]

    cpp.includePaths: [
        Drawing,
        Moving,
        Home,
    ]
}
