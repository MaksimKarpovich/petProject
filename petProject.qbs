import qbs

CppApplication {

    property string Home: path
    property string BSP: path + "/BSP"
    property string Drawing: BSP + "/Drawing"
    consoleApplication: true
    install: true
    files:[
        Home + "/main.c",
        Drawing + "/**",
    ]

    cpp.includePaths: [
        Drawing,
    ]
}
