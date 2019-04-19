(function($) {
  $(document).ready(function(){

    // $('#block-views-view-banner-block-1 .view-content').slick({
    //   arrows: false,
    //   slidesToShow:1,
    //   slidesToScroll: 1,
    //   autoplay: true,
    //   autoplaySpeed: 10000,
    //   dots:true,
    //   pauseOnHover: true,
    //   pauseOnFocus: false
    // });
    //
    //
    // $('#block-views-view-banner-block-1 .view-content .views-row').not('.slick-initialized').slick({
    //   arrows: true,
    //   slidesToShow:3,
    //   slidesToScroll: 1,
    //   dots:false,
    //   infinite: false,
    //   responsive: [
    //     {
    //       breakpoint: 992,
    //       settings: {
    //         slidesToShow: 2,
    //       }
    //     },
    //     {
    //       breakpoint: 500,
    //       settings: {
    //         slidesToShow: 1,
    //       }
    //     }
    //   ]
    // });
//     var tax = 0;
//     var tax_type = '';
//     var total_amount = $(".page-user-orders.page-user-orders- .component-type-commerce-price-formatted-amount  td.component-total").text();
//     $(".page-user-orders.page-user-orders- tr.all-taxes").each(function( index ) {
         
//          tax_type += $( this ).text() + "+";
//          total_tax = $("tr.all-taxes td.component-total:first").text();
//          total_tax = total_tax.replace(',','');
//          console.log(total_tax);

//          tax += parseFloat(total_tax.match(/[\d\.]+/));
//          console.log(tax);

// });
// tax_type = tax_type.slice(0,-1);
// var amount = $(".page-user-orders.page-user-orders- .view-commerce-line-item-table td.views-field-commerce-total").text();
// var taxes = '<div class="bill-summary container"><div class="total-amount-with-GST"> Total Amount: ' + amount +  '+ GST:  ₹' + tax + ' = '+ total_amount +'</div><div class="total-taxes-type">' + tax_type + '= ₹' +  tax + '</div></div>';

// $(".page-user-orders.page-user-orders- .bank-details").before(taxes);
// $(".page-user-orders.page-user-orders- .field-name-commerce-customer-billing").insertBefore(".page-user-orders.page-user-orders- .view-header .order-date-time.invoice-number");

// $(".page-user-orders.page-user-orders- .view-header .gstinno").insertAfter(".page-user-orders.page-user-orders- .field-name-commerce-customer-billing .field-name-field-phone-no");

// $(".page-user-orders.page-user-orders- .view-header .narration-section").insertAfter(".page-user-orders.page-user-orders- .bill-summary");




// $("body .print-button .print").click(function() {
//    window.print(); 
// });

// $(".page-node-add-advance-booking .field-name-field-select-product .form-select option[value='commerce_discount']").remove();
// $(".page-node-add-advance-booking .field-name-field-select-product .form-select option[value='shipping']").remove();
// $(".page-node-add-advance-booking .field-name-field-select-product .form-select option[value='product_discount']").remove();


  });
})(jQuery);
