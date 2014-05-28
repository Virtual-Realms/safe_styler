/**
 * TODO
 */
(function ($) {
  Drupal.behaviors.safeStylesUpdateFontPreview = {
    attach: function (context) {
      $(".font-family-select").once("fontpreviewchange", function() {
        $(this).change(function() {
          $(this).parent().next().children("span").removeClass().addClass($(this).val());
        }).trigger('change');
      });

    }
  };
})(jQuery);