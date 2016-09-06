function main()
    info()
    if checkAccess() then
        repeat
            io.write(User.getUserName() .. "@" .. GetName() .. ":" .. FileSystem.pwd() .. "$ ")
            io.flush()
            local line = io.read()

            execute(line)
        until line == "logout"
    else
        print("Access denied.")
    end
end

function checkAccess()
    return true
end

function execute(line)
    local sep = string.find(line, " ")
    local cmd = line
    local arg = ""
    if sep ~= nil then
        cmd = string.sub(line, 1, sep-1)
        arg = string.sub(line, sep+1)
    end

    if cmd == "logout" then return
    elseif cmd == "help" then
        print("Available commands:")
        print("help: this text")
        print("logout: disconnect from this system")
        print("info: display information about this system")
        print("ping: check whether a host is live")
        print("connect: connect to a remote host")
    elseif cmd == "info" then info()
    elseif cmd == "ping" then
        if Ping(arg) == true then
            print("Host is alive.")
        else
            print("Host is not responding.")
        end
    elseif cmd == "connect" then
        if not Connect(arg) then
            print("Cannot connect to host.")
        else
            print("Connection closed by remote host.")
        end
    elseif cmd == "run" then
        if not Run(arg) then
            print("Program not found: " .. arg)
        end
    elseif cmd == "pwd" then
        print(FileSystem.pwd())
    elseif cmd == "ls" then
        print(FileSystem.ls())
    elseif cmd == "cd" then
        if not FileSystem.cd(arg) then
            print("Directory not found: " .. arg)
        end
    elseif cmd == "cat" then
        print(FileSystem.cat(arg))
    else
        print("Command not found: " .. cmd)
    end
end

function info()
    print("Connected to " .. GetName())
end