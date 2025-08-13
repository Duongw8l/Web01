const info = localStorage.getItem('login');
const loginData = JSON.parse(info);

if (!loginData) {
    window.location.href = '../view/login.html';
}

const username1 = loginData.type;

if (username1 !== 'admin') {
    window.location.href = '../view/member.html';
} 
var logout = document.getElementById('logout');
logout.onclick = function() {
    localStorage.removeItem('login');
    window.location.href = '../index.html';
}

function displayUnapprovedQuestions() {
    const storedQuestionsJSON = localStorage.getItem('Questions');
    const storedQuestions = JSON.parse(storedQuestionsJSON) || [];


    const tableBody = document.getElementById('unapprovedQuestionsTable').getElementsByTagName('tbody')[0];

    storedQuestions.forEach(question => {
        const newRow = tableBody.insertRow();
        const cell1 = newRow.insertCell(0);
        const cell2 = newRow.insertCell(1);
        const cell3 = newRow.insertCell(2);
        const cell4 = newRow.insertCell(3);
        const cell5 = newRow.insertCell(4);
        const cell6 = newRow.insertCell(5);
        const cell7 = newRow.insertCell(6);
        const cell8 = newRow.insertCell(7);

        cell1.innerHTML = question.stt;
        cell2.innerHTML = question.timestamp.toLocaleString();
        cell3.innerHTML = question.question;
        cell4.innerHTML = question.answers.join(', ');
        cell5.innerHTML = question.answerstrue;
        cell6.innerHTML = question.username;
        cell7.innerHTML = question.status;
        cell8.innerHTML = `<button class="done" onclick="approveQuestion(${question.stt})">Duyệt</button> <br> <button class="nodone" onclick="disapproveQuestion(${question.stt})">Không duyệt</button>`;
        if (question.status === 'đã duyệt') {
            cell7.style.color = 'green';
        } else if (question.status === 'chưa duyệt') {
            cell7.style.color = 'orange'; 
        } else {
            cell7.style.color = 'red'; 
        }
    });
    
}


function approveQuestion(questionNumber) {
    const storedQuestionsJSON = localStorage.getItem('Questions');
    let storedQuestions = JSON.parse(storedQuestionsJSON) || [];

    storedQuestions = storedQuestions.map(question => {
        if (question.stt === questionNumber) {
            question.status = "đã duyệt";
        }
        return question;
    });

    localStorage.setItem('Questions', JSON.stringify(storedQuestions));

    alert('Đã duyệt câu hỏi thành công!')
    window.location.reload();
}

function disapproveQuestion(questionNumber) {
    const storedQuestionsJSON = localStorage.getItem('Questions');
    let storedQuestions = JSON.parse(storedQuestionsJSON) || [];

    storedQuestions = storedQuestions.map(question => {
        if (question.stt === questionNumber) {
            question.status = "không được duyệt";
        }
        return question;
    });

    localStorage.setItem('Questions', JSON.stringify(storedQuestions));

    alert('Câu hỏi không được duyệt!')
    window.location.reload();

    
    window.location.reload();
    
}


displayUnapprovedQuestions();