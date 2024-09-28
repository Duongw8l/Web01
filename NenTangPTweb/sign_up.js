const username = document.getElementById("username");
const password = document.getElementById("password");
const btn_dk = document.getElementById("btn_dk");

btn_dk.addEventListener("click", (e) =>{
  e.preventDefault();
  if(
      username.value === "" || password.value === ""
  ){
      alert("Vui lòng không để trống ! ")
  }
  else{
      const user = {
          username: username.value,
          password: password.value,
      
  };
  let json = JSON.stringify(user);
  localStorage.setItem(username.value, json);
  alert("Đăng Kí Thành Công!!!");
  window.location.href = "login.html";
  }
});