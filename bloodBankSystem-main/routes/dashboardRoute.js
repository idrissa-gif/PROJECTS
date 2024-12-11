const express = require('express');
const router = express.Router();

// GET request to render the dashboard page
router.get('/dashboard', (req, res) => {
    res.render('index'); // Assuming you have a "dashboard.ejs" template
});

module.exports = router;
