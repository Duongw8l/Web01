
function login() {
    const username = document.getElementById('username-id').value;
    const password = document.getElementById('password-id').value;

    
    const userDataJSON = localStorage.getItem('alluser');
    const alluser = JSON.parse(userDataJSON) || [];

    let check = false;
    let isAdmin = false;
    let userType = '';

    for (let i = 0; i < alluser.length; i++) {
        if (alluser[i].username === username && alluser[i].password === password) {
            check = true;
            userType = alluser[i].type; 
            if (userType === 'admin') {
                isAdmin = true;
            }
            break;
        }
    }

    if (isAdmin) {
        alert('Đăng nhập admin thành công!');

        const login = { username, password, type: userType }; 
        
        localStorage.setItem('login', JSON.stringify(login));

        window.location.href = '../index.html';
    } else {
        if (check) {
            const login = { username, password, type: userType }; 
          
            localStorage.setItem('login', JSON.stringify(login));

            alert('Đăng nhập thành công!');

            window.location.href = '../index.html'; 
        } else {
            alert('Đăng nhập thất bại. Vui lòng kiểm tra lại tên người dùng và mật khẩu.');
        }
    }
}
