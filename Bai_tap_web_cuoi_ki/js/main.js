const info = localStorage.getItem('login');
const loginData = JSON.parse(info);

const add = document.getElementById('logout');

if (!loginData) {
    add.innerHTML = 'Đăng nhập';

    add.addEventListener('click', function() {
        window.location.href = './view/login.html';
    });
} else {

    add.innerHTML = 'Đăng xuất';

    add.addEventListener('click', function() {
        localStorage.removeItem('login');
        window.location.href = './index.html';
    });
}

const username = loginData.username;
const namemember = document.getElementById('name');
namemember.textContent = 'Xin chào, ' + username;

if (loginData.type === 'admin') {
    const adminLink = document.getElementById('admin-cpanel');
    adminLink.href = './admin/index.html';
    adminLink.textContent = 'Trang quản trị';
}