const userModel = require('../models/userModel');

exports.getLoginPage = (req, res) => {
    res.render('login.ejs');
};

exports.login = (req, res) => {
    // Login logic
};
