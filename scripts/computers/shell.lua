function main()
    info()
    repeat
        local line
        io.write("$ ")
        io.flush()
        line = io.read()

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
    elseif line == "info" then info()
    else
        print("Command not found: " .. line)
    end
end

function info()
    print("Connected to " .. computer.getName())
end