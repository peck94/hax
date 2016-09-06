function main()
    info()
    repeat
        io.write("$ ")
        io.flush()
        local line = io.read()

        execute(line)
    until line == "logout"
end

function execute(line)
    if line == "exit" or line == "logout" then return
    elseif line == "help" then
        print("Available commands:")
        print("help: this text")
        print("logout: disconnect from this system")
        print("info: display information about this system")
        print("ping: check whether a host is live")
        print("connect: connect to a remote host")
    elseif line == "info" then info()
    elseif line == "ping" then
        io.write("host: ")
        io.flush()
        local host = io.read()
        if Ping(host) == true then
            print("Host is alive.")
        else
            print("Host is not responding.")
        end
    elseif line == "connect" then
        io.write("host: ")
        io.flush()
        local host = io.read()
        if not Connect(host) then
            print("Cannot connect to remote host.")
        end
    else
        print("Command not found: " .. line)
    end
end

function info()
    print("Connected to " .. GetName())
end