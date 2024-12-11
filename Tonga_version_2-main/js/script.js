let menu = document.querySelector('#menu-btn');
let navbar = document.querySelector('.header .navbar');
menu.onclick = () =>{
    menu.classList.toggle('fa-times');
    navbar.classList.toggle('active');
}


// var btn = document.getElementById('btn');
// btn.addEventListener('click',function (e){
// e.preventDefault();
// var name = document.getElementById('name').value;
// var subject = document.getElementById('subject').value;
// var email = document.getElementById('email').value;
// var message = document.getElementById('message').value;
// var body = 'name: '+name +'<br/> email: ' + email + '<br/> subject ' + subject + '<br/> message '+ message;

// Email.send({
//   Host : "smtp.gmail.com",
//   Username : "tongaagency@gmail.com",
//   Password : "trqqalfoykhtkbzd",
//   To : 'tongaagency@gmail.com',
//   From : email,
//   Subject : subject,
//   Body : body
// }).then(
//   message => alert(message)
// );

// })