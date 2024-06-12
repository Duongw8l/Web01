const username = document.getElementById("username");
const password = document.getElementById("password");
const btn_dn = document.getElementById("btn_dn");

btn_dn.addEventListener("click", (e)=>{
    e.preventDefault();
    if(
        username.value === "" ||
        password.value === ""
    ){
        alert("Vui lòng không để trống");
    }else{
        const user = JSON.parse(localStorage.getItem(username.value));
        if(
            user.username === username.value &&
            user.password === password.value
        ){
            alert("Đăng nhập thành công");
            window.location.href = "home.html";
        }else{
            alert("Đăng nhập thất bại");
        }
    }
})