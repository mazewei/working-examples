(function ($) {
    Drupal.behaviors.BefFix = {
        attach: function (context, settings) {
            var views_exposed_form = $('.views-exposed-form', context);

            views_exposed_form.hide();
            views_exposed_form.find('.form-control').not('.form-text, .form-select').removeClass('form-control');
            views_exposed_form.show();
        }
    };
    Drupal.behaviors.theme = {
        attach: function (context, settings) {

            $(document).ready(function () {

                var clickEvent = false;
                $('#myCarousel').carousel({
                    interval: 4000
                }).on('click', '.list-group li', function () {
                    clickEvent = true;
                    $('.list-group li').removeClass('active');
                    $('.list-group li white').removeClass('white');
                    $(this).addClass('active');
                    $('.list-group li white').addClass('white');
                }).on('slid.bs.carousel', function (e) {
                    if (!clickEvent) {
                        var count = $('.list-group').children().length - 1;
                        var current = $('.list-group li.active');
                        current.removeClass('active').next().addClass('active');
                        var id = parseInt(current.data('slide-to'));
                        if (count == id) {
                            $('.list-group li').first().addClass('active');
                        }
                    }
                    clickEvent = false;
                });
            })
        }
    }
})(jQuery);