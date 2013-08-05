
$(function() {
    $('.select_input').append(" \
      <option>Stage PC</option> \
      <option>Stage DVD Player</option> \
      <option>Control Booth PC</option> \
      <option>Control Booth DVD</option> \
      <option>Digital Signage</option> \
      <option>Blank</option> \
      <option>Blank</option> \
      <option>Blank</option> \
      <option>Blank</option>")

    $('#itoggle #check1').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check2').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check3').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check4').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check5').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check6').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check7').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
    $('#itoggle #check8').iToggle({
        type:      'checkbox',
        keepLabel: false,
        speed:     300,
        onClick: function(){
            //Function here
        },
        onClickOn: function(){
            //Function here
        },
        onClickOff: function(){
            //Function here
        },
        onSlide: function(){
            //Function here
        },
        onSlideOn: function(){
            //Function here
        },
        onSlideOff: function(){
            //Function here
        },
    });
   
// Column Highlighting
   
    $("table").delegate('td','mouseover mouseleave', function(e) {
      if (e.type == 'mouseover') {
        $(this).parent().addClass("hover");
        $("colgroup").eq($(this).index()).addClass("hover");
      }
      else
      {
        $(this).parent().removeClass("hover");
        $("colgroup").eq($(this).index()).removeClass("hover");
      }
    });
});