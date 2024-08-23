# Tarea 0

### Pasos seguidos
1. Clonar el repositorio de xv6-riscv
2. Instalar las herrramientas necesarias (Toolchains)
3. Instalar QEMU
4. Agregar el PATH
5. Ejecutar dentro de la carpeta de xv6-riscv el "make qemu"
6. Resolver el error mostrado por carpeta asociado a una libreria faltante, e instalarla.
7. Ejecutar un echo dentro del command shell de xv6

### Problemas
1. Al instalar "Toolchains" pensé que se quedaba pegado, solo era que se demoraba un poco ya que tenía un peso significativo, ejecute la instalación por varios nucleos y se solucionó ejecutandose bastante más rápido.

### Confirmación
1. La confirmacióne se observa junto a la imagen adjunta en webc.

# Tarea 1

### Funcionamiento
Se modificaron varios archivos:
1. user.h --> Este archivo es el que declara las llamadas al sistema, solo hay que definir la llamada 
    int getppid(void);
    int getancestor(int n);
2. usys.pl --> Este archivo es el que relaciona al usuario con las llamadas de kernel, permite que el usuario pueda usar estas funciones.
    entry("getppid");
    entry("getancestor");
3. syscall.h --> Este archivo es el que define y declara el número de las llamadas, además maneja las llamadas.
    #define SYS_getppid 22
    #define SYS_getancestor 23 
4. sysproc.c --> Este archivo es la lógica de las llamdas al kernel.
5. syscall.c -->  Este archivo es el que mapea los números del archivo syscall.h y los asigna según las funciones declaradas en el.
    extern uint64 sys_getppid(void);
    extern uint64 sys_getancestor(void);
    static uint64 (*syscalls[])(void) = {
        [SYS_getppid] sys_getppid,
        [SYS_getancestor]     sys_getancestor,
        }

### Funciones
    soytupadre 0 --> Retorna el mismo PID
    soytupadre 1 --> Retorna el padre PID
    soytupadre 2 --> Retorna el abuelo PID
            .
            .
            .
    soytupadre N --> Retorna -1 si no existe ese proceso
      
### Problemas
1. Tuve problemas al definir las llamadas que incluian argumentos, en el caso de getancestor antender como se pasan los parametros, puede ser que me haya olvidado algo de C...
2. Estuve como 30 minutos buscando un error hasta que me dí cuenta que eran unas minusculas en la palabra SYS_getancestor
