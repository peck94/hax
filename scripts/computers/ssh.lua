require "scripts/computers/shell"

user = "admin"
pass = "god"

function checkAccess()
    io.write("Username: ")
    io.flush()
    local name = io.read()
    io.write("Password: ")
    io.flush()
    local password = io.read()

    return name == user and password == pass
end