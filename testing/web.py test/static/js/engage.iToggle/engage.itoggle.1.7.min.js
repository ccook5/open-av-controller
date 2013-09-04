/*---------------
 * jQuery iToggle Plugin by Engage Interactive
 * Examples and documentation at: http://labs.engageinteractive.co.uk/itoggle/
 * Copyright (c) 2009 Engage Interactive
 * Version: 1.0 (10-JUN-2009)
 * Dual licensed under the MIT and GPL licenses:
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html

 * Version: 1.7 (30-May-2012) by pshiryaev
 * Requires: jQuery v1.7 or later
---------------*/
(function(a){a.fn.iToggle=function(g){function f(b,c){!0==b?"radio"==d.type?a("label[for="+c+"]").addClass("ilabel_radio"):a("label[for="+c+"]").addClass("ilabel"):a("label[for="+c+"]").remove()}function e(b,c){d.onClick.call(b);h=b.innerHeight();t=b.prop("for");b.hasClass("iTon")?(d.onClickOff.call(b),b.animate({backgroundPositionX:"100%",backgroundPositionY:"-"+h+"px"},d.speed,d.easing,function(){b.removeClass("iTon").addClass("iToff");clickEnabled=!0;d.onSlide.call(this);d.onSlideOff.call(this)}),
a("input#"+t).removeAttr("checked")):(d.onClickOn.call(b),b.animate({backgroundPositionX:"0%",backgroundPositionY:"-"+h+"px"},d.speed,d.easing,function(){b.removeClass("iToff").addClass("iTon");clickEnabled=!0;d.onSlide.call(this);d.onSlideOn.call(this)}),a("input#"+t).prop("checked","checked"));!0==c&&(name=a("#"+t).prop("name"),e(b.siblings("label[for]")))}clickEnabled=!0;var d=a.extend({},{type:"checkbox",keepLabel:!0,easing:!1,speed:200,onClick:function(){},onClickOn:function(){},onClickOff:function(){},
onSlide:function(){},onSlideOn:function(){},onSlideOff:function(){}},g);this.each(function(){var b=a(this);if(b.is("input")){var c=b.attr("id");f(d.keepLabel,c);if(b.attr("checked")){c=a('<label class="itoggle" for="'+c+'"><span></span></label>');b.addClass("iT_checkbox").before(c);var e=a(c).innerHeight();a(c).css({"background-position-x":"0%","background-position-y":"-"+e+"px"});b.prev("label").addClass("iTon")}else c=a('<label class="itoggle" for="'+c+'"><span></span></label>'),b.addClass("iT_checkbox").before(c),
e=a(c).innerHeight(),a(c).css({"background-position-x":"100%","background-position-y":"-"+e+"px"}),b.prev("label").addClass("iToff")}else b.children("input:"+d.type).each(function(){var b=a(this).attr("id");f(d.keepLabel,b);if(a(this).attr("checked")){b=a('<label class="itoggle" for="'+b+'"><span></span></label>');a(this).addClass("iT_checkbox").before(b);var c=a(b).innerHeight();a(b).css({"background-position-x":"0%","background-position-y":"-"+c+"px"});a(this).prev("label").addClass("iTon")}else b=
a('<label class="itoggle" for="'+b+'"><span></span></label>'),a(this).addClass("iT_checkbox").before(b),c=a(b).innerHeight(),a(b).css({"background-position-x":"100%","background-position-y":"-"+c+"px"}),a(this).prev("label").addClass("iToff");"radio"==d.type&&a(this).prev("label").addClass("iT_radio")})});a("label.itoggle").click(function(){!0==clickEnabled&&(clickEnabled=!1,a(this).hasClass("iT_radio")?a(this).hasClass("iTon")?clickEnabled=!0:e(a(this),!0):e(a(this)));return!1});a("label.ilabel").click(function(){!0==
clickEnabled&&(clickEnabled=!1,e(a(this).next("label.itoggle")));return!1})}})(jQuery);