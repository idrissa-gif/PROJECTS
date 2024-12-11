   // Get the modal element
        const modal = document.querySelector('.modal');

        // Add a mousedown event listener to the modal element
        modal.addEventListener('mousedown', function(event) {
            // Set a flag to indicate that the modal is being dragged
            isDragging = true;

            // Get the mouse position
            const mouseX = event.clientX;
            const mouseY = event.clientY;

            // Get the modal position
            const modalX = modal.getBoundingClientRect().left;
            const modalY = modal.getBoundingClientRect().top;

            // Calculate the offset between the mouse position and the modal position
            offsetX = mouseX - modalX;
            offsetY = mouseY - modalY;

            // Add a mousemove event listener to the document element
            document.addEventListener('mousemove', function(event) {
                // If the modal is being dragged, move it to the mouse position
                if (isDragging) {
                    modal.style.left = event.clientX - offsetX + 'px';
                    modal.style.top = event.clientY - offsetY + 'px';
                }
            });

            // Remove the mousemove event listener when the mouseup event is fired
            document.addEventListener('mouseup', function() {
                // Reset the flag to indicate that the modal is not being dragged
                isDragging = false;

                // Remove the mousemove event listener
                document.removeEventListener('mousemove');
            });
        });