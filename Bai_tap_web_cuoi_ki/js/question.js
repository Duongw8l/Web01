const info = localStorage.getItem('login');
const loginData = JSON.parse(info);
if (!loginData) {
    window.location.href = './login.html';
}

const username = loginData.username;
const namemember = document.getElementById('name');
namemember.textContent = 'Xin chào, ' + username;

var logout = document.getElementById('logout');
logout.onclick = function() {
    localStorage.removeItem('login');
    window.location.href = '../index.html';
}
if (loginData.type === 'admin') {
    const adminLink = document.getElementById('admin-cpanel');
    adminLink.href = '../admin/index.html';
    adminLink.textContent = 'Trang quản trị';
}

const storedQuestionsJSON = localStorage.getItem('Questions');
const storedQuestions = JSON.parse(storedQuestionsJSON) || [];


const approvedQuestions = storedQuestions.filter(question => question.status === 'đã duyệt');


const tbodyElement = document.getElementById('unapprovedQuestionsTable').getElementsByTagName('tbody')[0];


approvedQuestions.forEach(question => {
    const newRow = tbodyElement.insertRow();
    const cell1 = newRow.insertCell(0);
    const cell2 = newRow.insertCell(1);
    const cell3 = newRow.insertCell(2);
    const cell4 = newRow.insertCell(3);

    cell1.innerHTML = question.stt;
    cell2.innerHTML = question.timestamp.toLocaleString();
    cell3.innerHTML = question.question;
    cell4.innerHTML = question.answers.join(', ');
});
