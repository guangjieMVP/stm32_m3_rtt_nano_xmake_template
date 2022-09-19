-- 设置工程名
set_project("stm32_rtt_nano_demo")

-- 设置工程版本
set_version("1.0.0")

add_rules("mode.debug", "mode.release")

-- 自定义工具链
toolchain("arm-none-eabi")
    -- 标记为自定义独立工具链
    set_kind("standalone")
    -- 定义交叉编译工具链地址，根据工具链的实际位置修改
    set_sdkdir("C:\\gcc-arm-none-eabi\\10 2021.10")   
toolchain_end()

target("rtt_thread.elf")
    -- 编译为二进制程序
    set_kind("binary") 
    -- 设置使用的交叉编译工具链
    set_toolchains("arm-none-eabi")  

    -- 设置平台
    set_plat("cross")
    -- 设置架构
    set_arch("m3")

    -- 设置编译生成程序名字，不设置就会使用target("rtt_thread.elf")里面的名字
    --set_filename("rtt_thread.elf")
    set_languages("gnu11")

    add_defines(
        "USE_HAL_DRIVER",  -- 使用HAL库
        "STM32F103xB"  -- 参考 libraries\STM32F1xx_HAL\CMSIS\Device\ST\STM32F1xx\Include\stm32f1xx.h 60行 进行设置   
    )

    -- 添加链接库
    add_links("c", "m");  -- 或者链接选项添加 ：-lc -lm -lnosys -lrdimon 
    
    add_cflags(
        "-Og",
        "-mcpu=cortex-m3",
        "-mthumb",
        "-Wall",
        "-fdata-sections",
        "-ffunction-sections",
        "-g3 -gdwarf-2",
        "--specs=nano.specs", 
        {force = true}
    )

    add_asflags(
        "-Og",
        "-mcpu=cortex-m3",
        "-mthumb",
       "-x assembler-with-cpp",
        "-Wall",
        "-fdata-sections", 
        "-ffunction-sections",
        "-g3 -gdwarf-2",
        {force = true}
    )

    add_ldflags(
        "-Og",
        "-mcpu=cortex-m3",
        "-TSTM32F103C8Tx_FLASH.ld",  -- 不同芯片需要修改链接脚本 STM32F103XE_FLASH.ld STM32F103C8Tx_FLASH.ld
        "-Wl,--gc-sections",
        "--specs=nosys.specs",
        "--specs=nano.specs",  -- 减小代码尺寸
        "-u _printf_float",  
        {force = true}
    )
    
    -- 源文件和头文件路径
    local src_path = {
        "applications",
        "drivers",
        "libraries/STM32F1xx_HAL_Driver/Src",
        "drivers/bsp",
    }
    -- 头文件路径
    local inc_path = {
        "applications",
        "drivers",
        "drivers/bsp",
        "libraries/STM32F1xx_HAL_Driver/Inc",
        "libraries/CMSIS/Device/ST/STM32F1xx/Include",
        "libraries/CMSIS/Include",
        "config",
    }
    -- rtt source files
    local rtt_src = {
        "rt-thread/src",
        "rt-thread/libcpu/arm/cortex-m3",
        "rt-thread/components/finsh",
    }
    -- rtt header files
    local rtt_inc = {
        "rt-thread/include",
        "rt-thread",
        "rt-thread/components/finsh",
        "rt-thread/components/drivers/include/drivers"
    }
    -- rtt线程调度相关的汇编文件
    add_files("rt-thread/libcpu/arm/cortex-m3/context_gcc.S")

    -- 添加启动文件 根据芯片选择
    add_files("startup_stm32f103xb.s");

    for _, dir in ipairs(src_path) do  -- 遍历 src_path
        add_files(dir.."/*.c"); 
    end

     for _, dir in ipairs(rtt_src) do  -- 遍历 rtt_src
        add_files(dir.."/*.c"); 
    end

    -- 添加头文件路径
    for _, inc in ipairs(inc_path) do
        add_includedirs(inc);
    end

    for _, inc in ipairs(rtt_inc) do
        add_includedirs(inc);
    end
   
    if is_mode("debug") then 
        -- add_cflags("-g", "-gdwarf-2")
        add_defines("DEBUG")
    end

    after_build(
        function(target)
        cprint("Compile finished!!!")

        if is_mode("release") then
            print("release finished")
            os.exec("arm-none-eabi-objcopy -O ihex ./build/cross/m3/release/rtt_thread.elf ./build/rtt_thread.hex")
            os.exec("arm-none-eabi-objcopy -O binary ./build/cross/m3/release/rtt_thread.elf ./build/rtt_thread.bin")
        end

        if is_mode("debug") then
            print("debug finished")
            os.exec("arm-none-eabi-objcopy -O ihex ./build/cross/m3/debug/rtt_thread.elf ./build/rtt_thread.hex")
            os.exec("arm-none-eabi-objcopy -O binary ./build/cross/m3/debug/rtt_thread.elf ./build/rtt_thread.bin")
        end

        print("Generate hex and bin files ok!!!")

        print(" ");
        print("********************储存空间占用情况*****************************")
        if is_mode("release") then
            os.exec("arm-none-eabi-size -Ax ./build/cross/m3/release/rtt_thread.elf")
            os.exec("arm-none-eabi-size -Bx ./build/cross/m3/release/rtt_thread.elf")
            os.exec("arm-none-eabi-size -Bd ./build/cross/m3/release/rtt_thread.elf")
        end

        if is_mode("debug") then
            os.exec("arm-none-eabi-size -Ax ./build/cross/m3/debug/rtt_thread.elf")
            os.exec("arm-none-eabi-size -Bx ./build/cross/m3/debug/rtt_thread.elf")
            os.exec("arm-none-eabi-size -Bd ./build/cross/m3/debug/rtt_thread.elf")
        end
        --print("heap-堆, stack-栈, .data-已初始化的变量全局/静态变量, .bss-未初始化的data, .text-代码和常量")
        -- os.run("arm-none-eabi-objdump.exe -D ./build/cross/m3/release/rtt_thread.elf > rtt_thread.s")
        -- os.exec("arm-none-eabi-objdump -h -S ./build/cross/m3/debug/rtt_thread.elf > rtt_thread.list")
    end)