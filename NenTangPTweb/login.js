const username = document.getElementById("username");
const password = document.getElementById("password");
const btn_dn = document.getElementById("btn_dn"); // lấy ra các phần tử html có id tương ứng 

btn_dn.addEventListener("click", (e)=>{ //gắn sự kiện click cho nút đăng nhập
    e.preventDefault(); // sự kiện tránh hành vi mặc định của form
    if(
        username.value === "" || password.value === ""       
    ){ 
        alert("Vui lòng không để trống");
    }else{
        const user = JSON.parse(localStorage.getItem(username.value));
        if( user.username === username.value && user.password === password.value ){    
            alert("Đăng nhập thành công");
            window.location.href = "index.html";  
        }
        else{
            alert("Đăng nhập thất bại");
        }
    }
})