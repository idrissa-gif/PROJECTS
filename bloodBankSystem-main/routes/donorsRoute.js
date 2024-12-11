// routes/donors.js
const express = require('express');
const router = express.Router();
const donorsController = require('../controllers/donorsController'); // Correct the import

router.get('/donors', donorsController.getAllDonors);
// For adding a donor
router.get('/add', donorsController.getAddDonorPage); // Corrected to use donorsController
//router.post('/donors/add', donorsController.addDonor); // Corrected to use donorsController

// // For editing a donor
// router.get('/donors/edit/:id', donorsController.getEditDonorPage); // Corrected to use donorsController
// router.post('/donors/edit/:id', donorsController.editDonor); // Corrected to use donorsController

// // For removing a donor
// router.get('/donors/remove/:id', donorsController.getRemoveDonorPage); // Corrected to use donorsController
// router.post('/donors/remove/:id', donorsController.removeDonor); // Corrected to use donorsController

module.exports = router;
