(function($) {
Drupal.behaviors.show_popup = {
attach: function (context, settings) {

console.log("attach");
console.log(Drupal.settings.show_popup);

}
};})(jQuery);