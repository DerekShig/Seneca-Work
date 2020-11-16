/* global countriesData, ui, util */

window.onload = function () {
  // Load table at window load
  let countryList = util.countriesByLanguage('English');
  ui.countriesToTable(countryList, 'English');

  // Subtitle
  let subtitle = document.querySelector('#subtitle');

  // Languages
  let languages = document.querySelectorAll('#languages li a');
  languages.forEach((e) => {
    e.addEventListener('click', () => {
      let language = e.innerHTML;
      let countryList = util.countriesByLanguage(language);
      ui.countriesToTable(countryList, language);
      subtitle.innerHTML = `List of Countries and Dependencies - ${language}`;
    });
  });

  // Sort by Population
  let sort100m = document.querySelector('#menu_population_100_000_000m');
  sort100m.addEventListener('click', () => {
    let list = util.countriesByPopulation(100000000);
    ui.countriesToTable(list, 'English');
    subtitle.innerHTML = 'List of Countries and Dependencies - Population over 100,000,000';
  });

  let sort1m = document.querySelector('#menu_population_1m_2m');
  sort1m.addEventListener('click', () => {
    let list = util.countriesByPopulation(1000000, 2000000);
    ui.countriesToTable(list, 'English');
    subtitle.innerHTML =
      'List of Countries and Dependencies - Population between 1,000,000 and 2,000,000';
  });

  // Sort by Area & Continent
  let areaOver1m = document.querySelector('#menu_americas_1mkm');
  areaOver1m.addEventListener('click', () => {
    let list = util.countriesByAreaAndContinent('Americas', 1000000);
    ui.countriesToTable(list, 'English');
    subtitle.innerHTML =
      'List of Countries and Dependencies - Countries in Americas with land over 1,000,000 km<sup>2</sup>';
  });

  let allSize = document.querySelector('#menu_asia_all');
  allSize.addEventListener('click', () => {
    let list = util.countriesByAreaAndContinent('Asia', 0);
    ui.countriesToTable(list, 'English');
    subtitle.innerHTML =
      'List of Countries and Dependencies - Countries in Asia with any land size';
  });
};
