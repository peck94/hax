function main()
    info()
    if checkAccess() then
        repeat
            io.write(GetName() .. ":" .. GetDir() .. "$ ")
            io.flush()
            local line = io.read()

            execute(line)
        until line == "logout"
    else
        print("Access denied.")
    end

    print("Connection closed by remote host.")
end

function checkAccess()
    return true
end

function execute(line)
    if line == "logout" then return
    elseif line == "help" then
        print("Available commands:")
        print("help: this text")
        print("logout: disconnect from this system")
        print("info: display information about this system")
        print("ping: check whether a host is live")
        print("connect: connect to a remote host")
    elseif line == "info" then info()
    elseif line == "ping" then
        io.write("Host: ")
        io.flush()
        local host = io.read()
        if Ping(host) == true then
            print("Host is alive.")
        else
            print("Host is not responding.")
        end
    elseif line == "connect" then
        io.write("Host: ")
        io.flush()
        local host = io.read()
    elseif line == "run" then
        io.write("program: ")
        io.flush()
        local prog = io.read()
        if not Run(prog) then
            print("Program not found: " .. prog)
        end
    else
        print("Command not found: " .. line)
    end
end

function info()
    print("Connected to " .. GetName())
end