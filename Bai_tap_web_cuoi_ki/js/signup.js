function signup() {
  
    const username = document.getElementById('username-id').value;
    const password = document.getElementById('password-id').value;
    const admin = document.getElementById('admin-id').value;

    if (username.trim() === '' || password.trim() === '') {
        alert('Vui lòng nhập đầy đủ thông tin.');
        return;
    }

    if (username.length < 6) {
        alert('Tên người dùng phải có ít nhất 6 kí tự.');
        return;
    }


    if (password.length < 8) {
        alert('Mật khẩu phải có ít nhất 8 kí tự.');
        return;
    }
    var type = 'user';
    if(admin === '9') {
        type = 'admin';
    }
   
    const userDataJSON = localStorage.getItem('alluser');
    const alluser = JSON.parse(userDataJSON) || [];

  
    let isUsernameTaken = false;

    for (let i = 0; i < alluser.length; i++) {
        if (alluser[i].username === username) {
            isUsernameTaken = true;
            break;
        }
    }

    if (isUsernameTaken) {
        alert('Tên người dùng đã được sử dụng.');
        return;
    }


    const newUser = { username, password ,type};
    alluser.push(newUser);
    localStorage.setItem('alluser', JSON.stringify(alluser));

    alert('Tạo tài khoản thành công, chuyển hướng sang trang login.');
    window.location.href = 'login.html';
}
