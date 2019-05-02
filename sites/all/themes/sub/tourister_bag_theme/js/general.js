(function($) {
  Drupal.behaviors.regsiter_ngo = {
    attach: function (context, settings) {

      // Show Popup or not
      if (typeof Drupal.settings.accessories_controller !== 'undefined' && typeof Drupal.settings.accessories_controller.show_popup !== 'undefined') {
        var show_popup = Drupal.settings.accessories_controller.show_popup;
        console.log(show_popup);
        if (show_popup == 1) {
          $('.region-content .popup-custom').show();
        }
        else {
          $('.region-content .popup-custom').hide();
        }
      }

      // Popup js
      if ($('.region-content .popup-custom').length) {
        // close button
        $('.region-content .popup-custom .close').click(function() {
          $('.popup-custom').fadeOut();
        });

        // Accept terms - Send ajax request
        if ($('.region-content .popup-custom .accept a').length) {
          $('.region-content .popup-custom .accept a').on('click', function(e) {
            $.ajax({
              url: "/accept-terms-conditions",
              cache: false,
              success: function(data){
                if (data == 'user-accepted') {
                  $('.popup-custom .popup-custom-inner').html('Thank you for accepting out terms and conditons. Now you can order from our website.');
                  setTimeout(function(){
                    $('.popup-custom').fadeOut();
                  }, 1000);
                }
              }
            });
          });
        }
      }
    }
  }
})(jQuery);