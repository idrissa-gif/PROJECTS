//js/donors.js

$(document).ready(function () {
    // Handle Remove Donor button click
    $('.remove-donor-button').on('click', function () {
        const donorId = $(this).data('donor-id');
        // Implement code to send an AJAX request to remove the donor with donorId
        // After a successful removal, remove the corresponding row from the table.
        // Example AJAX request:
        // $.ajax({
        //     type: 'DELETE',
        //     url: `/donors/remove/${donorId}`,
        //     success: function () {
        //         // Remove the corresponding row from the table
        //         $(`tr[data-donor-id="${donorId}"]`).remove();
        //     },
        //     error: function (error) {
        //         console.log('Error:', error);
        //     }
        // });
    });

    // Handle Edit Donor button click
    $('.edit-donor-button').on('click', function () {
        const donorId = $(this).data('donor-id');
        // Implement code to display an edit form for the donor with donorId
        // You can use a modal or a form within the page to edit donor details.
        // Example code:
        // Show an edit form with the donor's details for editing.
    });

   $('.add-donor-button').on('click', function () {
    // Get the add-donor.ejs content using AJAX
    $.get('/add')
        .done(function (data) {
            // Success: data contains the fetched HTML

            // Create a modal to display the add-donor.ejs content
            const modal = $('<div>')
                .addClass('modal fade')
                .attr('id', 'addDonorModal')
                .html(data);

            // Add the modal to the DOM
            $('body').append(modal);

            // Show the modal
            $('#addDonorModal').modal('show');
            
        })
        .fail(function (xhr, status, error) {
            console.log('AJAX error: ' + error);
        });
        $('#addDonorModal').on('hidden.bs.modal', function () {
        // Close the modal
        $(this).modal('hide');
});
});
});
