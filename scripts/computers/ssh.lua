require "scripts/computers/shell"

function checkAccess()
    io.write("Username: ")
    io.flush()
    local name = io.read()
    io.write("Password: ")
    io.flush()
    local password = io.read()

    if not HasUser(name) then
        return false
    end

    GetUser(name)
    return User.getUserName() == name and User.getPassword() == password
end
