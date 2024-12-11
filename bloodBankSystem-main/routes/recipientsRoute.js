const express = require('express');
const router = express.Router();

// GET request to render the recipients page
router.get('/',(req,res)=>{
    res.render('recipients');
});

module.exports = router;
