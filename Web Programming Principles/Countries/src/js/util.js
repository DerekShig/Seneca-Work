/**
 * Helper object for working with countries data and extracting information.
 * See countries-data.js for format of the countries data set.
 */

// eslint-disable-next-line no-unused-vars
const util = {
  /**
   * Given a language name, returns the 2-letter language code for this language.
   * Supports all of the following languages:
   *
   *  - English: "en"
   *  - Arabic: "ar"
   *  - Chinese: "zh"
   *  - French: "fr"
   *  - Hindi: "hi"
   *  - Korean: "ko"
   *  - Japanese: "ja"
   *  - Russian: "ru"
   *
   * If any other language is passed, return null
   *
   * For example:
   *
   * util.langCodeForLanguage('Korean') returns "ko"
   * util.langCodeForLanguage('German') returns null (i.e., not one of the supported languages)
   *
   * @param {String} language - the full language name
   */
  langCodeForLanguage(language) {
    let code = '';
    switch (language) {
      case 'English':
        code = 'en';
        break;
      case 'Arabic':
        code = 'ar';
        break;
      case 'Chinese':
        code = 'zh';
        break;
      case 'French':
        code = 'fr';
        break;
      case 'Hindi':
        code = 'hi';
        break;
      case 'Korean':
        code = 'ko';
        break;
      case 'Japanese':
        code = 'ja';
        break;
      case 'Russian':
        code = 'ru';
        break;
      default:
        code = null;
        break;
    }
    return code;
  },

  /**
   * Formats a given number for display using the specified language.
   *
   * For example, given a number 652230 and language "Russian", return
   * the string:
   *
   * '652 230'
   *
   * Or if the language is "Hindi", return the string:
   *
   * '6,52,230'
   *
   * Your function should use util.langCodeForLanguage to map the language name to a language code.
   *
   * Use Intl.NumberFormat to generate the formatted numbers for each locale, see:
   *
   * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat
   *
   * @param {Number} number - the number to format
   * @param {String} language - the language name to use
   */
  formatNumberForLanguage(number, language) {
    return new Intl.NumberFormat(this.langCodeForLanguage(language)).format(number);
  },

  /**
   * Returns a copy of the given country Object with the name property switched
   * to the specified language, and numbers formatted for this language. For example,
   * if the following country object is passed:
   *
   * {
   *   code: 'AF',
   *   continent: 'Asia',
   *   areaInKm2: 652230,
   *   population: 35530081,
   *   capital: 'Kabul',
   *   name: {
   *     English: 'Afghanistan',
   *     Arabic: 'أفغانستان',
   *     Chinese: '阿富汗',
   *     French: 'Afghanistan',
   *     Hindi: 'अफ़ग़ानिस्तान',
   *     Korean: '아프가니스탄',
   *     Japanese: 'アフガニスタン',
   *     Russian: 'Афганистан'
   *   }
   * }
   *
   * And if the language parameter is "Korean", return the following new object:
   *
   * {
   *   code: 'AF',
   *   continent: 'Asia',
   *   areaInKm2: '652,230',
   *   population: '35,530,081'
   *   capital: 'Kabul',
   *   name: '아프가니스탄',
   * }
   *
   * NOTE: do not modify the original object.  Create and return a new one.
   *
   * You should support the following languages:
   *
   * English, Arabic, Chinese, French, Hindi, Korean, Japanese, Russian
   *
   * If any other language is passed, throw an error indicating that an unrecognized
   * language name was used.
   *
   * NOTE: you should call `util.formatNumberForLanguage` to format the areaInKm2
   * and population values for the given language.
   *
   * @param {Object} country - the country object to use
   * @param {String} language - the language name to use
   */
  countryForLanguage: function (country, language) {
    let obj = {};
    let supported = [
      'English',
      'Arabic',
      'Chinese',
      'French',
      'Hindi',
      'Korean',
      'Japanese',
      'Russian'
    ];
    if (supported.indexOf(language) >= 0) {
      obj['code'] = country.code;
      obj['name'] = country['name'][language];
      obj['continent'] = country.continent;
      obj['areaInKm2'] = this.formatNumberForLanguage(country.areaInKm2, language);
      obj['population'] = this.formatNumberForLanguage(country.population, language);
      obj['capital'] = country.capital;
    } else {
      throw 'Invalid language';
    }
    return obj;
  },

  /**
   * Return an array of all countries, with the `name` property replaced by the
   * appropriate translation, or English if not specified (or unknown).  For
   * example, when language="English", you would process the Object for Canada into:
   *
   * {
   *     code: "CA",
   *     continent: "Americas",
   *     areaInKm2: "9,984,670",
   *     population: "36,624,199",
   *     capital: "Ottawa",
   *     name: "Canada"
   * }
   *
   * Supported languages include:
   *
   * English, Arabic, Chinese, French, Hindi, Korean, Japanese, Russian
   *
   * Uses `countriesData` as the underlying array of countries to be processed
   * and `util.countryForLanguage`.
   *
   * @param {String} language - the language name to use
   */
  countriesByLanguage: function (language) {
    let arr = [];
    let supported = [
      'English',
      'Arabic',
      'Chinese',
      'French',
      'Hindi',
      'Korean',
      'Japanese',
      'Russian'
    ];
    if (supported.indexOf(language) == -1) {
      language = 'English';
    }
    for (const con in countriesData) {
      arr.push(this.countryForLanguage(countriesData[con], language));
    }
    return arr;
  },

  /**
   * Return an array of countries with a population greater than or equal to
   * `minPopulation`, and possibly less than equal to `maxPopulation` (if defined)
   * otherwise allow any number greater than `minPopulation`.
   *
   * Use `util.countriesByLanguage('English')` to get English names for countries
   * by default (i.e., you don't need to support multiple languages for population)
   *
   * @param {Number} minPopulation - (Required) minimum population value
   * @param {Number} maxPopulation - (Optional) maximum population value
   */
  countriesByPopulation: function (minPopulation, maxPopulation = Infinity) {
    let arr = [];
    let countries = this.countriesByLanguage('English');
    for (const con in countries) {
      let population = parseInt(countries[con].population.replace(/,/g, ''));
      if (population >= minPopulation && population < maxPopulation) {
        arr.push(countries[con]);
      }
    }
    return arr;
  },

  /**
   * Return an array of countries for the given `continent` with an area
   * greater than or equal to the given `area` in square KM.
   *
   * Use `util.countriesByLanguage('English')` to get English names for countries
   * by default (i.e., you don't need to support multiple languages for area)
   *
   * @param {String} continent - (Required) name of the continent (e.g., Europe)
   * @param {Number} minArea - (Required) minimum number of KM2 area
   */
  countriesByAreaAndContinent: function (continent, minArea) {
    let arr = [];
    let countries = this.countriesByLanguage('English');
    for (const con in countries) {
      let area = parseInt(countries[con].areaInKm2.replace(/,/g, ''));
      if (countries[con].continent == continent && area >= minArea) {
        arr.push(countries[con]);
      }
    }
    return arr;
  }
};
