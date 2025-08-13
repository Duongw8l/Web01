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

function showformsingle() {
    const questionFormContainer2 = document.getElementById('showwriting');
    questionFormContainer2.style.display = 'none';
    const questionFormContainer = document.getElementById('showsingle');
    questionFormContainer.style.display = 'block';
}
function showformwriting() {
    const questionFormContainer2 = document.getElementById('showsingle');
    questionFormContainer2.style.display = 'none';
    const questionFormContainer = document.getElementById('showwriting');
    questionFormContainer.style.display = 'block';
}

function displayUserQuestions() {
    const storedQuestionsJSON = localStorage.getItem('Questions');
    const storedQuestions = JSON.parse(storedQuestionsJSON) || [];

    const userQuestions = storedQuestions.filter(question => question.username === username);

    userQuestions.forEach(question => addRowToTable(question));
}

displayUserQuestions();

function saveQuestion() {
    const question = document.getElementById('singlequestion').value;
    const answerA = document.getElementById('answer1').value;
    const answerB = document.getElementById('answer2').value;
    const answerC = document.getElementById('answer3').value;
    const answerD = document.getElementById('answer4').value;
    const answersingletrue = document.getElementById('answersingletrue').value;

    if (!question || !answerA || !answerB || !answerC || !answerD || !answersingletrue) {
        alert('Vui lòng nhập đầy đủ thông tin câu hỏi và đáp án.');
        return;
    }
    
    if (answersingletrue !== answerA && answersingletrue !== answerB && answersingletrue !== answerC && answersingletrue !== answerD) {
        alert('Đáp án đúng nhập không đúng, vui lòng kiểm tra lại.');
        return;
    }

    const storedQuestionsJSON = localStorage.getItem('Questions');
    const storedQuestions = JSON.parse(storedQuestionsJSON) || [];
    const questionNumber = storedQuestions.length + 1;

    const newQuestion = {
        stt: questionNumber,
        timestamp: new Date().toLocaleString('vi-VN'), 
        question: question,
        answers: [answerA, answerB, answerC, answerD],
        answerstrue: answersingletrue,
        status: 'chưa duyệt',
        username: username,
        type: 'single'
    };
    
    storedQuestions.push(newQuestion);
    localStorage.setItem('Questions', JSON.stringify(storedQuestions));
    addRowToTable(newQuestion);
    alert('Câu hỏi đã được lưu thành công.');
    document.getElementById('singleqs').reset();
    location.reload();
}


function writingquestion() {

    const questionFillIn = document.getElementById('questionFillIn').value;
    const answerFillIn = document.getElementById('answerFillIn').value;

    if (!questionFillIn || !answerFillIn) {
        alert('Vui lòng nhập đầy đủ thông tin câu hỏi và đáp án.');
        return;
    }

    
    const answers = answerFillIn.split('\n').map(answer => answer.trim());

    if (answers.length === 0) {
        alert('Vui lòng nhập ít nhất một đáp án.');
        return;
    }

    const storedQuestionsFillInJSON = localStorage.getItem('Questions');
    const storedQuestionsFillIn = JSON.parse(storedQuestionsFillInJSON) || [];

    const questionNumber = storedQuestionsFillIn.length + 1;
    const newQuestion = {
        stt: questionNumber,
        timestamp: new Date().toLocaleString('vi-VN'),
        question: questionFillIn,
        answers: answers,
        answerstrue: answers[0], 
        status: 'chưa duyệt',
        username: username,
        type: 'writting'
    };

    storedQuestionsFillIn.push(newQuestion);
    localStorage.setItem('Questions', JSON.stringify(storedQuestionsFillIn));


    addRowToTable(newQuestion);

    alert('Câu hỏi (Điền đáp án) đã được lưu thành công.');
    document.getElementById('quizFormFillIn').reset();
    location.reload();
}

function addRowToTable(question) {
    const tableBody = document.getElementById('questionTable').getElementsByTagName('tbody')[0];
    const newRow = tableBody.insertRow();
    const cell1 = newRow.insertCell(0);
    const cell2 = newRow.insertCell(1);
    const cell3 = newRow.insertCell(2);
    const cell4 = newRow.insertCell(3);
    const cell5 = newRow.insertCell(4);
    const cell6 = newRow.insertCell(5);
    const cell7 = newRow.insertCell(6);

    cell1.innerHTML = question.stt;
    cell2.innerHTML = question.timestamp.toLocaleString();
    cell3.innerHTML = question.question;
    cell4.innerHTML = question.answers.join(', ');
    cell5.innerHTML = question.answerstrue;
    cell6.innerHTML = question.status;
    

    const editButton = document.createElement('button');
    editButton.innerHTML = 'Sửa';
    editButton.id = 'editButton';
    editButton.onclick = function() {

        if (question.type === 'writting') {
            var hide = document.getElementById('editwriting');
            hide.style.display = 'none';
            alert('Đang ở chế độ sửa câu hỏi');
            showformwriting();
            var editsingle = document.getElementById('edit_writing');
            editsingle.innerHTML = `<button onclick="updateQuestionwriting(${question.stt})">Sửa Câu Hỏi</button>`;
            
        } 
        if (question.type === 'single') {
            var hide = document.getElementById('save_questionsingle');
            hide.style.display = 'none';
            alert('Đang ở chế độ sửa câu hỏi');
            showformsingle();
            var editsingle = document.getElementById('edit_single');
            editsingle.innerHTML = `<button onclick="updateQuestionsingle(${question.stt})">Sửa Câu Hỏi</button>`;

        }  
    };
    cell7.appendChild(editButton);
    const deleteButton = document.createElement('button');
    deleteButton.innerHTML = 'Xóa';
    deleteButton.id = 'deleteButton';
    deleteButton.onclick = function() {
    
        if (confirm('Bạn có chắc muốn xóa câu hỏi này không?')) {
            const storedQuestionsJSON = localStorage.getItem('Questions');
            let storedQuestions = JSON.parse(storedQuestionsJSON) || [];

        
            storedQuestions = storedQuestions.filter(q => q.stt !== question.stt);

         
            localStorage.setItem('Questions', JSON.stringify(storedQuestions));

        
            location.reload();
        }
    };
    cell7.appendChild(deleteButton);
    if (question.status === 'đã duyệt') {
        cell6.style.color = 'green';
    } else {
        cell6.style.color = 'red'; 
    }
}



function updateQuestionsingle(index) {
    
    const editedQuestion = document.getElementById('singlequestion').value;
    const editedAnswer1 = document.getElementById('answer1').value;
    const editedAnswer2 = document.getElementById('answer2').value;
    const editedAnswer3 = document.getElementById('answer3').value;
    const editedAnswer4 = document.getElementById('answer4').value;
    const editedAnswerTrue = document.getElementById('answersingletrue').value;
    if (!editedQuestion || !editedAnswer4 || !editedAnswer1 || !editedAnswer2 || !editedAnswer3 || !editedQuestion) {
        alert('Vui lòng nhập đầy đủ thông tin câu hỏi và đáp án.');
        return;
    }
    
    if (editedAnswerTrue !== editedAnswer1 && editedAnswerTrue !== editedAnswer2 && editedAnswerTrue !== editedAnswer3 && editedAnswerTrue !== editedAnswer4) {
        alert('Đáp án đúng nhập không đúng, vui lòng kiểm tra lại.');
        return;
    }
   
    const questionIndexToEdit = index - 1;
    const storedQuestionsJSON = localStorage.getItem('Questions');
    const storedQuestions = JSON.parse(storedQuestionsJSON) || [];
    storedQuestions[questionIndexToEdit].question = editedQuestion;
    storedQuestions[questionIndexToEdit].answers = [editedAnswer1, editedAnswer2, editedAnswer3, editedAnswer4];
    storedQuestions[questionIndexToEdit].answerstrue = editedAnswerTrue;
    storedQuestions[questionIndexToEdit].status = 'chưa duyệt';
    localStorage.setItem('Questions', JSON.stringify(storedQuestions));
}

function updateQuestionwriting(index) {
 
    const editedQuestion = document.getElementById('questionFillIn').value;
    const answer = document.getElementById('answerFillIn').value;
    const questionIndexToEdit = index - 1;
    const storedQuestionsJSON = localStorage.getItem('Questions');
    const storedQuestions = JSON.parse(storedQuestionsJSON) || [];
    storedQuestions[questionIndexToEdit].question = editedQuestion;
    storedQuestions[questionIndexToEdit].answers = [answer];
    storedQuestions[questionIndexToEdit].answerstrue = answer;
    storedQuestions[questionIndexToEdit].status = 'chưa duyệt';
    localStorage.setItem('Questions', JSON.stringify(storedQuestions));
}

